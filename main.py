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
        # __get__ __set__
        
    def catchInfo(self) -> None:
        self.qtd_letras = int(input("\nDigite a quantidade de letras do alfabeto: "))

        for i in range(self.qtd_letras):
            letra = input(f"\tDigite a letra {i+1}: ")
            self.alfabeto.append(letra)
        self.qtd_alfabeto_aux = int(input("Digite a quantidade de letras do alfabeto auxiliar: "))

        for i in range(self.qtd_alfabeto_aux):
            letra = input(f"\tDigite a letra {i+1} do alfabeto auxiliar: ")
            self.alfabeto_aux.append(letra)

        self.qtd_estados = int(input("Digite a quantidade de estados: "))
        self.estado_inicial = int(input("Informe o estado inicial: "))
        self.qtd_estados_finais = int(input("Digite a quantidade de estados finais: "))
        for i in range(self.qtd_estados_finais):
            letra = input(f"\tDigite o estado final {i+1}: ")


    

maquina1 = Turing()
maquina1.catchInfo()
