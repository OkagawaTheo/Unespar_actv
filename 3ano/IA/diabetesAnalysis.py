import pandas as pd

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
      print(self.df.head())
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
      zeroesCount = (self.df[column_name]=='0').sum()
      print(f"-{column_name}: {zeroesCount} zeroes")

      

if __name__ == "__main__":
  file_path = '/home/okwath/unespar/Unespar_actv/3ano/IA/archive/diabetes.csv'
  instanceDiabetes = DiabetesAnalysis(file_path=file_path)
  instanceDiabetes.handleImpossibleVar()