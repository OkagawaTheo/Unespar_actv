import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score,precision_score,recall_score,f1_score,confusion_matrix

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

    print(f"Divisao concluida: {len(x_train)} - Treino\n{len(x_test)} - Teste") 
    return x_train,x_test,y_train,y_test
  
class _Node: #classe construtora do node xd
  def __init__(self,column_id=None,left_child=None,right_child=None,value=None):
    self.column_id = column_id
    self.left_child = left_child
    self.right_child = right_child
    self.value = value

class DecisionTree:
  def __init__(self,maxDepth=None,min_samples_split=2,criterio="gini"):
    self.maxDepth = maxDepth
    self.min_samples_split = min_samples_split
    self.criterio = criterio
    self.tree = None

  def calculate_gini(self,y): #calculo impureza pra um conjunto y
    classes,counts = np.unique(y,return_counts=True)
    gini = 1.0
    for count in counts:
      p_i = count /len(y)
      gini -= p_i**2
    return gini
  
  def calculate_entropy(self,y): 
    classes, counts = np.unique(y,return_counts=True)
    entropy = 0.0
    for count in counts:
      p_i = count/len(y)
      if p_i > 0:
        entropy -= p_i*np.log2(p_i)
    return entropy

  def calculate_information_gain(self,parent_y,left_y,right_y):
    parent_entropy = self.calculate_entropy(parent_y)
    n_parent = len(parent_y)
    n_left = len(left_y)
    n_right = len(right_y)
    child_entropy = (n_left / n_parent) * self._calculate_entropy(left_y) + \
    (n_right / n_parent) * self._calculate_entropy(right_y)
    return parent_entropy - child_entropy

  def calculate_gain_ratio(self,parent_y,left_y,right_y):
    information_gain = self.calculate_information_gain(parent_y,left_y,right_y)
    n_parent = len(parent_y)
    n_left = len(left_y)
    n_right = len(right_y)
    split_info = 0.0
    if n_left > 0:
        p_left = n_left / n_parent
        split_info -= p_left * np.log2(p_left)
    if n_right > 0:
          p_right = n_right / n_parent
          split_info -= p_right * np.log2(p_right)
    if split_info == 0:
          return 0.0
    return information_gain / split_info
      
  def find_best_split(self,x,y): #melhor feature e threshold
    best_gain = 0.0
    best_feature_id = None
    best_threshold = None

    if len(y) == 0 or len(np.unique(y)) == 1:
      return None, None, 0
    x_np = x.values
    
if __name__ == "__main__":
  file_path = '/home/okwath/unespar/Unespar_actv/3ano/IA/archive/diabetes.csv'
  instanceDiabetes = DiabetesAnalysis(file_path=file_path)
  instanceDiabetes.handleImpossibleVar()