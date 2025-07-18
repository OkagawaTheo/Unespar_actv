import pandas as pd

class DiabetesAnalysis:
  def __init__(self,file_path,data_columns):
    self.file_path = file_path
    self.num_columns = data_columns
    self.df = None

  def LoadData(self):
    try:
      self.df = pd.read_csv(file_path)
      print("Carregado.")
      print(self.df.head())
    except FileNotFoundError:
      print("Arquivo não encontrado.")
    except Exception as e:
      print(f"Erro ao carregar o dataSet '{e}'")


if __name__ == "__main__":
  file_path = '/home/okwath/unespar/Unespar_actv/3ano/IA/archive/diabetes.csv'
  data_columns = ["Pregnancies", "Glucose", "BloodPressure", "SkinThickness", "Insulin", "BMI","DiabetesPedigreeFunction","Age","Outcome"]
  instance = DiabetesAnalysis(file_path=file_path,data_columns=data_columns)
  instance.LoadData()