class Turing:
    def __init__(self):
        self.qtd_letras = 0
        self.alfabeto = []
        self.qtd_alfabeto_aux = 0
        self.alfabeto_aux = []
        self.qtd_estados = 0
        self.estados = []
        self.estado_inicial = ""
        self.qtd_estados_finais = 0
        self.estados_finais = []
        self.marcador_inicio = ""
        self.marcador_branco = ""
        self.funcao_Transicao = {}

    def catchInfo(self):
        self.qtd_letras = int(input("\nDigite a quantidade de letras do alfabeto: "))
        for i in range(self.qtd_letras):
            letra = input(f"\tDigite a letra {i + 1}: ")
            self.alfabeto.append(letra)
        
        self.qtd_alfabeto_aux = int(input("Digite a quantidade de letras do alfabeto auxiliar: "))
        for i in range(self.qtd_alfabeto_aux):
            letra = input(f"\tDigite a letra {i + 1} do alfabeto auxiliar: ")
            self.alfabeto_aux.append(letra)
        
        self.qtd_estados = int(input("Digite a quantidade de estados: "))
        for i in range(self.qtd_estados):
            estado = input(f"\tDigite o nome do estado {i + 1}: ")
            self.estados.append(estado)

        self.estado_inicial = input("Digite o estado inicial: ")
        
        self.qtd_estados_finais = int(input("Quantidade de estados finais: "))
        for i in range(self.qtd_estados_finais):
            estado_final = input(f"\tDigite o estado final {i + 1}: ")
            self.estados_finais.append(estado_final)

        self.marcador_inicio = input("Digite um símbolo para marcador inicial: ")
        self.marcador_branco = input("Insira um símbolo para branco: ")

        print("Preencha as transições:") 
        for estado in self.estados:
            for simbolo in self.alfabeto + self.alfabeto_aux + [self.marcador_inicio, self.marcador_branco]:
                transicao = input(f" δ ({estado},{simbolo}): ").strip()

                if transicao.upper() == "X":
                    self.funcao_Transicao[(estado, simbolo)] = None
                    
                else:
                        proximo_estado, simbolo_para_escrever, direcao = transicao.split(",")
                        self.funcao_Transicao[(estado, simbolo)] = (proximo_estado, simbolo_para_escrever, direcao)
                    

    def executar_MT(self):
        while True:
            entrada_usuario = list(input("Insira a palavra a ser verificada: ")) 
           
            if not all(char in self.alfabeto for char in entrada_usuario):
                print("Palavra não aceita. Símbolos inválidos.")
                continue

            # Inicialização da fita e da cabeça de leitura/escrita
            fita = [self.marcador_inicio] + entrada_usuario + [self.marcador_branco] * 100  # Adicionando espaço branco na fita
            posicao_cabeca = 1  # Começa após o marcador inicial
            estado_atual = self.estado_inicial
            palavra_aceita = False  

            while True:
                simbolo_atual = fita[posicao_cabeca]
                transicao = self.funcao_Transicao.get((estado_atual, simbolo_atual))

                if transicao is None:  # Transição inválida
                    break

                proximo_estado, simbolo_para_escrever, direcao = transicao

            
                fita[posicao_cabeca] = simbolo_para_escrever
                if direcao == "R":
                    posicao_cabeca += 1
                elif direcao == "L":
                    posicao_cabeca -= 1

                estado_atual = proximo_estado

                if estado_atual in self.estados_finais:
                    palavra_aceita = True
                    break

            if palavra_aceita:
                print("Palavra aceita.")
            else:
                print("Palavra não aceita.")

maquina1 = Turing()
maquina1.catchInfo()
maquina1.executar_MT()
