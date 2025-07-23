import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
# dividir dados pra treino/teste check
#funcoes pras metricas recall f1-score blablablablabla boring ass trabalho
class DiabetesAnalysis:
  def __init__(self, file_path):
    self.file_path = file_path
    self.df = None
    self.LoadData()

  def LoadData(self):
    try:
      self.df = pd.read_csv(self.file_path)
      print("Carregado com sucesso")
    except FileNotFoundError:
      print("Arquivo não encontrado.")
      self.df = None
    except Exception as e:
      print(f"Erro ao carregar o dataSet '{e}'")
      self.df = None

  def handleImpossibleVar(self):
    print("\nIniciando tratamento de variaveis impossiveis.")
    if self.df is None:
      print("DataFrame nao carregado corretamente")
      return
    
    TroubleCauserVars = ["Glucose", "BloodPressure","SkinThickness","Insulin","BMI"]
    for column_name in TroubleCauserVars:
      self.df[column_name] = self.df[column_name].replace(0,np.nan)
      self.df[column_name] = pd.to_numeric(self.df[column_name],errors='coerce')
      medianValue = self.df[column_name].median()
      self.df[column_name] = self.df[column_name].replace(np.nan,medianValue)
      print(f"\t-> Mediana de {column_name}: {medianValue:.2f} aplicada na coluna.")
    print("\nTratamento de variáveis impossíveis concluido.\n")
    print(self.df.head())
      
  def splitData(self,testSize=0.2,random_state=26):
    if self.df is None:
      print("DataFrame nao carregado corretamente.")
      return None,None,None,None
    
    x = self.df.drop('Outcome',axis=1)
    y = self.df['Outcome']

    x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=testSize,random_state=random_state)

    return x_train,x_test,y_train,y_test

    print(f"Divisao concluida: {len(x_train)} - Treino\n{len(x_test)} - Teste")
if __name__ == "__main__":
  file_path = '/home/okwath/unespar/Unespar_actv/3ano/IA/archive/diabetes.csv'
  instanceDiabetes = DiabetesAnalysis(file_path=file_path)
  instanceDiabetes.handleImpossibleVar()