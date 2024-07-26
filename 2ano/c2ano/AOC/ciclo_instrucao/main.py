def menu():
    print("="*30)
    print("""
1 - Inserir
2 - Ver Instruções
3 - Executar
4 - Sair
""")
    print("="*30)

class CicloInstrucao:
    def __init__(self):
        self.PC = 0;
        self.MBR = 0
        self.flagZero = False
        self.flagNegativo = False
        self.memoria = [0]*256
        self.instrucoes = []

    def entrada_usuario(self):
        print("Digite as instruções do programa (4 para sair da inserção)");
        while(True):
            instrucao = input("Digite o codigo da instrução: ")
            if instrucao == '4':
                break;
            op1 = op2 = ""
            if instrucao not in ["000001","001010","001011","001100"]:
                op1 = input("Digite o primeiro operando: ")
                if instrucao not in ["000011", "000100", "000101", "000110", "000111", "001000", "001001", "001111"]:
                    op2 = input("Digite o segundo operando: ")
                
            self.instrucoes.append(f"{op1},{op2}") #append formatado por virgula
            print(self.instrucoes)

                
        #instructions
        # "000001": "MBR <- #POS",
        # "000010": "POS <- #DADO",
        #"000011": "MBR <- MBR + #POS",
        #"000100": "MBR <- MBR - #POS",
        # "000101": "MBR <- MBR * #POS",
        #"000110": "MBR <- MBR / #POS",
        # "000111": "JUMP to #LIN",
        # "001000": "JUMP IF Z to #LIN",
        # "001001": "JUMP IF N to #LIN",
        # "001010": "MBR <- raiz_quadrada(MBR)",
        # "001011": "MBR <- -MBR",
        #"001111": "#POS <- MBR",
        # "001100": "NOP"
        
    def ver_instrucoes(self):
        print("="*30)
        print("= INSTRUÇÕES: =")
        print("="*30)
        print(f"{'COD':<10} {'OP1':<10} {'OP2':<10} {'RESULTADOS':<25}")
        instrucoes_desc = {
            "000001": "MBR <- #POS",
            "000010": "POS <- #DADO",
            "000011": "MBR <- MBR + #POS",
            "000100": "MBR <- MBR - #POS",
            "000101": "MBR <- MBR * #POS",
            "000110": "MBR <- MBR / #POS",
            "000111": "JUMP to #LIN",
            "001000": "JUMP IF Z to #LIN",
            "001001": "JUMP IF N to #LIN",
            "001010": "MBR <- raiz_quadrada(MBR)",
            "001011": "MBR <- -MBR",
            "001111": "#POS <- MBR",
            "001100": "NOP"
        }
        for instrucao in self.instrucoes:
            print(instrucao)

    def executar_instrucoes(self):
        print("="*30)
        print("EXECUTANDO")
        print("="*30)
        for instrucao in self.instrucoes:
            self.executar_instrucoes(instrucao)
            print()



ci = CicloInstrucao()
menu();
# ci.entrada_usuario()
ci.ver_instrucoes()