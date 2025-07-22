import pandas as pd
import numpy as np

class DiabetesAnalysis:
  def __init__(self, file_path):
    self.header_columns = ["Pregnancies", "Glucose", "BloodPressure", "SkinThickness", "Insulin", "BMI", "DiabetesPedigreeFunction", "Age", "Outcome"]
    self.file_path = file_path
    self.df = None
    self.LoadData()

  def LoadData(self):
    try:
      self.df = pd.read_csv(self.file_path,names=self.header_columns,header=None)
      print("Carregado com sucesso")
      # print(self.df.head())
    except FileNotFoundError:
      print("Arquivo não encontrado.")
      self.df = None
    except Exception as e:
      print(f"Erro ao carregar o dataSet '{e}'")
      self.df = None

  def handleImpossibleVar(self):
    if self.df is None:
      print("DataFrame nao carregado corretamente")
      return
    
    TroubleCauserVars = ["Glucose", "BloodPressure","SkinThickness","Insulin","BMI"]
    for column_name in TroubleCauserVars:
      self.df[column_name] = self.df[column_name].replace('0',np.nan)
      self.df[column_name] = pd.to_numeric(self.df[column_name],errors='coerce')
      medianValue = self.df[column_name].median()
      self.df[column_name] = self.df[column_name].replace('0',np.nan)
      print(f"Mediana de {column_name}: {medianValue:.2f} aplicada na coluna.")
    print("Tratamento de variáveis impossíveis concluido.")
  
    #substituir pelas medianas check
    #replace .nan check
    #.median check
      

if __name__ == "__main__":
  file_path = '/home/okwath/unespar/Unespar_actv/3ano/IA/archive/diabetes.csv'
  instanceDiabetes = DiabetesAnalysis(file_path=file_path)
  instanceDiabetes.handleImpossibleVar()