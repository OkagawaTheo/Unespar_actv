import tkinter as tk
from tkinter import filedialog
from pytube import YouTube
import os
from moviepy import AudioFileClip

def selectTxtFile():
    root = tk.Tk()
    root.withdraw()
    file_path = filedialog.askopenfilename(
        title="Selecione o arquivo TXT com os links das músicas",
        filetypes=[("Arquivos de Texto", "*.txt")]
    )
    return file_path

def selectDestinationFolder():
    root = tk.Tk()
    root.withdraw()
    folder_path = filedialog.askdirectory(
        title="Selecione a pasta para salvar as músicas MP3"
    )
    return folder_path

def downloadAndConvert(link, folder_path):
    try:
        yt = YouTube(link)
        print(f"Processando: {yt.title}")

        audio_stream = yt.streams.filter(only_audio=True).order_by('abr').desc().first()

        if not audio_stream:
            print(f"Nenhuma faixa de áudio encontrada para {link}")
            return

        clean_title = "".join(c for c in yt.title if c.isalnum() or c in (' ', '.', '_')).rstrip()
        
        audio_stream_downloaded_path = audio_stream.download(output_path=folder_path, filename=f"{clean_title}.mp4")
        print("Download concluído.")

        mp3_file_path = os.path.join(folder_path, f"{clean_title}.mp3")
        print(f"Convertendo para MP3: {mp3_file_path}")

        audio_clip = AudioFileClip(audio_stream_downloaded_path)
        audio_clip.write_audiofile(mp3_file_path)
        audio_clip.close()

        os.remove(audio_stream_downloaded_path)
        print(f"Conversão para MP3 concluída: {mp3_file_path}")

    except Exception as e:
        print(f"Ocorreu um erro ao processar o link {link}: {e}")

def main():
    print("Conversor de Links do YouTube para MP3")

    caminho_arquivo_txt = selectTxtFile()
    if not caminho_arquivo_txt:
        print("Nenhum arquivo TXT selecionado.")
        return

    pasta_destino = selectDestinationFolder()
    if not pasta_destino:
        print("Nenhuma pasta de destino selecionada.")
        return

    try:
        with open(caminho_arquivo_txt, 'r') as f:
            links = f.readlines()

        print(f"\nIniciando o processamento de {len(links)} links")
        for i, link in enumerate(links):
            link = link.strip()
            if link:
                print(f"\nProcessando link {i+1}/{len(links)}")
                downloadAndConvert(link, pasta_destino)

        print("\nPronto paizao")

    except FileNotFoundError:
        print(f"Arquivo '{caminho_arquivo_txt}' não foi encontrado.")
    except Exception as e:
        print(f"Ocorreu um erro inesperado: {e}")

if __name__ == "__main__":
    main()