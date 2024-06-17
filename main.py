class Turing:
    def __init__(self):
        self.qtd_letras: int = 0
        self.alfabeto: list[str] = []
        self.alfabeto_aux: list[str] = []
        self.qtd_estados: int = 0
        self.estado_inicial: str = ""
        self.qtd_estados_finais: int = 0
        self.estados_finais: list[str] = []
        self.marcador_inicio: str = ""
        self.marcador_final: str = ""
        
    def pegarInfos(self) -> None:
        self.qtd_letras = int(input("Digite a quantidade de letras do alfabeto: "))

        for i in range(self.qtd_letras):
            letra = input(f"Digite a letra {i+1}: ")
            self.alfabeto.append(letra)

maquina1 = Turing()
maquina1.pegarInfos()
