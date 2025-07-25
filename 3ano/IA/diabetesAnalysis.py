import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix

class DiabetesAnalysis:
    def __init__(self, file_path):
        self.header_columns = ["Pregnancies", "Glucose", "BloodPressure", "SkinThickness", "Insulin", "BMI", "DiabetesPedigreeFunction", "Age", "Outcome"]
        self.file_path = file_path
        self.df = None
        self.LoadData()

    def LoadData(self):
        try:
            self.df = pd.read_csv(self.file_path, names=self.header_columns, header=None, skiprows=1)
            print("Dataset carregado com sucesso.")
        except FileNotFoundError:
            print("Arquivo não encontrado.")
            self.df = None
        except Exception as e:
            print(f"Erro ao carregar o dataSet: '{e}'")
            self.df = None

    def handleImpossibleVar(self):
        print("\nIniciando tratamento de variáveis impossíveis.")
        if self.df is None:
            print("DataFrame não carregado corretamente.")
            return
        
        TroubleCauserVars = ["Glucose", "BloodPressure","SkinThickness","Insulin","BMI"]
        for column_name in TroubleCauserVars:
            self.df[column_name] = self.df[column_name].replace(0,np.nan)
            self.df[column_name] = pd.to_numeric(self.df[column_name],errors='coerce')
            medianValue = self.df[column_name].median()
            self.df[column_name] = self.df[column_name].fillna(medianValue)
            print(f"  Mediana de {column_name}: {medianValue:.2f} aplicada.")
        print("Tratamento de variáveis impossíveis concluído.\n")
        print("Amostras iniciais após tratamento:")
        print(self.df.head())
        
    def splitData(self,testSize=0.2,random_state=26):
        if self.df is None:
            print("DataFrame nao carregado corretamente.")
            return None,None,None,None
        
        x = self.df.drop('Outcome',axis=1)
        y = self.df['Outcome']

        x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=testSize,random_state=random_state)

        print(f"\nDivisão concluída: {len(x_train)} amostras de treino | {len(x_test)} amostras de teste.") 
        return x_train,x_test,y_train,y_test
    
    def evaluate_model(self, y_true, y_pred, name="Modelo"):
        print(f"\n--- {name} ---") 
        print(f"Acurácia: {accuracy_score(y_true, y_pred):.4f}")
        precision = precision_score(y_true, y_pred, pos_label=1)
        print(f"Precisão (Positiva): {precision:.4f}")
        recall = recall_score(y_true, y_pred, pos_label=1)
        print(f"Recall (Positiva): {recall:.4f}")
        f1 = f1_score(y_true, y_pred, pos_label=1)
        print(f"F1-score (Positiva): {f1:.4f}")
        cm = confusion_matrix(y_true, y_pred)
        print("Matriz de Confusão:")
        print(cm)
        print(f"  TN: {cm[0,0]} | FP: {cm[0,1]}")
        print(f"  FN: {cm[1,0]} | TP: {cm[1,1]}")
        print("------------------------------------------")


class _Node:
    def __init__(self, column_id=None, threshold=None, left_child=None, right_child=None, value=None):
        self.column_id = column_id
        self.threshold = threshold 
        self.left_child = left_child
        self.right_child = right_child
        self.value = value

class DecisionTree:
    def __init__(self, max_depth=3, min_samples_split=10, criterion="gini"): 
        self.max_depth = max_depth 
        self.min_samples_split = min_samples_split
        self.criterion = criterion
        self.tree = None

    def calculate_gini(self, y):
        classes, counts = np.unique(y, return_counts=True)
        gini = 1.0
        for count in counts:
            p_i = count / len(y)
            gini -= p_i**2
        return gini
    
    def calculate_entropy(self, y): 
        classes, counts = np.unique(y, return_counts=True)
        entropy = 0.0
        for count in counts:
            p_i = count / len(y)
            if p_i > 0:
                entropy -= p_i * np.log2(p_i)
        return entropy

    def calculate_information_gain(self, parent_y, left_y, right_y):
        parent_entropy = self.calculate_entropy(parent_y)
        n_parent = len(parent_y)
        n_left = len(left_y)
        n_right = len(right_y)
        child_entropy = (n_left / n_parent) * self.calculate_entropy(left_y) + \
                        (n_right / n_parent) * self.calculate_entropy(right_y)
        return parent_entropy - child_entropy

    def calculate_gain_ratio(self, parent_y, left_y, right_y):
        information_gain = self.calculate_information_gain(parent_y, left_y, right_y)
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
        
    def find_best_split(self, X, y):
        best_gain = 0.0 # CORRIGIDO: Inicializado com 0.0
        best_feature_idx = None
        best_threshold = None

        if len(y) == 0 or len(np.unique(y)) == 1:
            return None, None, 0.0 

        X_np = X.values

        for feature_idx in range(X.shape[1]):
            current_feature_values = X_np[:, feature_idx] 
            possible_thresholds = np.unique(current_feature_values)

            for threshold in possible_thresholds:
                left_mask = current_feature_values <= threshold
                right_mask = ~left_mask

                if np.sum(left_mask) == 0 or np.sum(right_mask) == 0:
                    continue

                left_y, right_y = y[left_mask], y[right_mask]

                current_gain = 0.0
                if self.criterion == "gini":
                    parent_gini = self.calculate_gini(y)
                    n_total = len(y)
                    weighted_child_gini = (len(left_y) / n_total) * self.calculate_gini(left_y) + \
                                          (len(right_y) / n_total) * self.calculate_gini(right_y)
                    current_gain = parent_gini - weighted_child_gini

                elif self.criterion == "information_gain":
                    current_gain = self.calculate_information_gain(y, left_y, right_y)
                elif self.criterion == "gain_ratio":
                    current_gain = self.calculate_gain_ratio(y, left_y, right_y)
                else:
                    raise ValueError("Critério não suportado.")

                if current_gain > best_gain:
                    best_gain = current_gain
                    best_feature_idx = feature_idx
                    best_threshold = threshold
        
        return best_feature_idx, best_threshold, best_gain 
    
    def _build_tree(self, X, y, depth):
        if len(np.unique(y)) == 1:
            return _Node(value=y.iloc[0])

        if self.max_depth is not None and depth >= self.max_depth:
            return _Node(value=y.mode()[0])

        if len(y) < self.min_samples_split:
            return _Node(value=y.mode()[0])

        feature_idx, threshold, gain = self.find_best_split(X, y)

        if gain == 0 or feature_idx is None:
            return _Node(value=y.mode()[0])
        
        feature_values = X.iloc[:, feature_idx].values 
        left_mask = feature_values <= threshold
        right_mask = ~left_mask

        left_X, left_y = X[left_mask].copy(), y[left_mask].copy() 
        right_X, right_y = X[right_mask].copy(), y[right_mask].copy()

        left_child = self._build_tree(left_X, left_y, depth + 1)
        right_child = self._build_tree(right_X, right_y, depth + 1)

        return _Node(column_id=feature_idx, 
                     threshold=threshold, 
                     left_child=left_child, 
                     right_child=right_child)

    def fit(self, X, y):
        X_reset = X.reset_index(drop=True) 
        y_reset = y.reset_index(drop=True)
        self.tree = self._build_tree(X_reset, y_reset, depth=0)

    def _traverse_tree(self, x, node):
        if node.value is not None:
            return node.value
        
        if x.iloc[node.column_id] <= node.threshold: 
            return self._traverse_tree(x, node.left_child) 
        else:
            return self._traverse_tree(x, node.right_child) 

    def predict(self, X):
        predictions = [self._traverse_tree(X.iloc[i], self.tree) for i in range(len(X))]
        return np.array(predictions)


if __name__ == "__main__":
    file_path = '/home/okwath/unespar/Unespar_actv/3ano/IA/archive/diabetes.csv'
    
    instanceDiabetes = DiabetesAnalysis(file_path=file_path)
    instanceDiabetes.handleImpossibleVar()

    X_train, X_test, y_train, y_test = instanceDiabetes.splitData(testSize=0.25, random_state=42)

    print("\n\nINICIANDO TREINAMENTO E AVALIAÇÃO") 

    print("\n### ÁRVORE: CRITÉRIO GINI ###")
    tree_gini = DecisionTree(criterion="gini", max_depth=3, min_samples_split=10)
    print("  Treinando modelo Gini...")
    tree_gini.fit(X_train, y_train)
    print("  Gerando previsões para Gini...")
    y_pred_gini_train = tree_gini.predict(X_train)
    y_pred_gini_test = tree_gini.predict(X_test)
    
    print("\nResultados para Gini - Treino")
    instanceDiabetes.evaluate_model(y_train, y_pred_gini_train, name="Gini - Treino")
    
    print("\nResultados para Gini - Teste")
    instanceDiabetes.evaluate_model(y_test, y_pred_gini_test, name="Gini - Teste")

    print("\n### ÁRVORE: CRITÉRIO INFORMATION GAIN ###")
    tree_ig = DecisionTree(criterion="information_gain", max_depth=3, min_samples_split=10)
    print("  Treinando modelo Information Gain...")
    tree_ig.fit(X_train, y_train)
    print("  Gerando previsões para Information Gain...")
    y_pred_ig_train = tree_ig.predict(X_train)
    y_pred_ig_test = tree_ig.predict(X_test)
    
    print("\nResultados para Information Gain - Treino")
    instanceDiabetes.evaluate_model(y_train, y_pred_ig_train, name="Information Gain - Treino")
    
    print("\nResultados para Information Gain - Teste")
    instanceDiabetes.evaluate_model(y_test, y_pred_ig_test, name="Information Gain - Teste")

    print("\n### ÁRVORE: CRITÉRIO GAIN RATIO ###")
    tree_gr = DecisionTree(criterion="gain_ratio", max_depth=3, min_samples_split=10)
    print("  Treinando modelo Gain Ratio...")
    tree_gr.fit(X_train, y_train)
    print("  Gerando previsões para Gain Ratio...")
    y_pred_gr_train = tree_gr.predict(X_train)
    y_pred_gr_test = tree_gr.predict(X_test)
    
    print("\nResultados para Gain Ratio - Treino")
    instanceDiabetes.evaluate_model(y_train, y_pred_gr_train, name="Gain Ratio - Treino")
    
    print("\nResultados para Gain Ratio - Teste")
    instanceDiabetes.evaluate_model(y_test, y_pred_gr_test, name="Gain Ratio - Teste")

# estava tendo muito problema com overfitting, porem 10 samples e 3 de maxDepth é uma poda agressiva porém trouxe uma redução de ~11% de discrepancia treino-teste