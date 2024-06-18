class Turing:
    def __init__(self):
        self.qtd_letras: int = 0
        self.alfabeto: list[str] = []
        self.qtd_alfabeto_aux: int = 0
        self.alfabeto_aux: list[str] = []
        self.qtd_estados: int = 0
        self.estado_inicial: str = ""
        self.qtd_estados_finais: int = 0
        self.estados_finais: list[str] = []
        self.marcador_inicio: str = ""
        self.marcador_final: str = ""
        
    def catchInfo(self) -> None:
        self.qtd_letras = int(input("Digite a quantidade de letras do alfabeto: "))

        for i in range(self.qtd_letras):
            letra = input(f"\tDigite a letra {i+1}: ")
            self.alfabeto.append(letra)
        self.qtd_alfabeto_aux = int(input("Digite a quantidade de letras do alfabeto auxiliar: "))

        for i in range(self.qtd_alfabeto_aux):
            letra = input("Digite a letra do alfabeto auxiliar: ")
            self.alfabeto_aux.append(letra)
            print(self.alfabeto_aux[0])
            print(self.alfabeto[0])    
maquina1 = Turing()
maquina1.catchInfo()
