Here's a comprehensive tutorial covering **Data Processing, Cleaning, and Manipulation** along with **Exploratory Data Analysis (EDA)** in Python.

---

# **Tutorial: Data Processing, Cleaning, and Exploratory Data Analysis in Python**

### **1. Prerequisites**
Ensure you have the following Python libraries installed:
```bash
pip install pandas numpy matplotlib seaborn
```

---

## **2. Data Processing and Cleaning**

### **Step 1: Importing Libraries**
```python
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
```

### **Step 2: Load the Dataset
Load your dataset into a Pandas DataFrame:
```python
# Example dataset: Titanic Dataset
url = "https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv"
df = pd.read_csv(url)
```
Certainly! Here are additional methods for **loading datasets** from various sources:

---

### **1. Load Local CSV Files
```python
df = pd.read_csv('your_file.csv')
```

### Load Excel Files
```python
df = pd.read_excel('your_file.xlsx', sheet_name='Sheet1')
```

### Load JSON Files
```python
df = pd.read_json('your_file.json')
```



### Load Data from an API
```python
import requests

# Fetch data from an API
url = "https://api.example.com/data"
response = requests.get(url)
data = response.json()

# Convert JSON to a DataFrame
df = pd.DataFrame(data)
```

### Load Data from Google Sheets
Use `gspread` to access Google Sheets:
```bash
pip install gspread pandas
```
```python
import gspread
from oauth2client.service_account import ServiceAccountCredentials

# Define the scope and credentials
scope = ['https://spreadsheets.google.com/feeds', 'https://www.googleapis.com/auth/drive']
credentials = ServiceAccountCredentials.from_json_keyfile_name('your_credentials.json', scope)

# Authenticate and open the sheet
client = gspread.authorize(credentials)
sheet = client.open("Your Sheet Name").sheet1

# Load data into a DataFrame
data = sheet.get_all_records()
df = pd.DataFrame(data)
```
### Load Data from ZIP Files
```python
import zipfile

# Extract ZIP file
with zipfile.ZipFile('your_file.zip', 'r') as z:
    z.extractall('extracted_files')

# Load data
df = pd.read_csv('extracted_files/your_file.csv')
```

### Load Large Datasets in Chunks
For very large files, load them in chunks:
```python
chunk_size = 10000
chunks = pd.read_csv('large_file.csv', chunksize=chunk_size)

# Combine chunks if necessary
df = pd.concat(chunks, ignore_index=True)
```

### Load Data from Parquet Files
```python
df = pd.read_parquet('your_file.parquet')
```

---

### Load Data from Web Scraping
Use `BeautifulSoup` for scraping tabular data:
```python
import requests
from bs4 import BeautifulSoup

# Get the web page
url = "https://example.com/data"
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

# Extract table data
table = soup.find('table')
df = pd.read_html(str(table))[0]
```



### **Step 3: Initial Inspection**
```python
# Display first few rows
print(df.head())

# Check data structure
print(df.info())

# Summary statistics
print(df.describe())
```

### **Step 4: Handling Missing Values**
```python
# Check for missing values
print(df.isnull().sum())

# Fill missing numeric values with the median
df['Age'] = df['Age'].fillna(df['Age'].median())

# Fill categorical missing values with the mode
df['Embarked'] = df['Embarked'].fillna(df['Embarked'].mode()[0])

# Drop columns with too many missing values (e.g., 'Cabin')
df = df.drop(columns=['Cabin'])
```
Handling missing values effectively is crucial for ensuring data quality. Below are detailed techniques for handling missing values:

---

### **Step 1: Identify Missing Values**
```python
# Summary of missing values
print(df.isnull().sum())

# Percentage of missing values
print(df.isnull().mean() * 100)

# Visualize missing values
import missingno as msno
msno.matrix(df)
plt.show()
```

---

### **Drop Missing Values**
**Drop Rows with Missing Values**
   ```python
   df_dropped_rows = df.dropna()
   print(f"Shape after dropping rows: {df_dropped_rows.shape}")
   ```

**Drop Columns with Too Many Missing Values**
   ```python
   # Drop columns with more than 50% missing values
   threshold = 0.5
   df_dropped_cols = df.loc[:, df.isnull().mean() < threshold]
   print(f"Shape after dropping columns: {df_dropped_cols.shape}")
   ```

---

### **Imputation Methods**

**Fill with Constants**

   - Useful for categorical data.
   ```python
   df['CategoryColumn'] = df['CategoryColumn'].fillna('Unknown')
   ```

    **Fill with Statistical Measures**
   - For numerical columns:
     ```python
     # Mean
     df['NumericColumn'] = df['NumericColumn'].fillna(df['NumericColumn'].mean())

     # Median
     df['NumericColumn'] = df['NumericColumn'].fillna(df['NumericColumn'].median())

     # Mode
     df['CategoryColumn'] = df['CategoryColumn'].fillna(df['CategoryColumn'].mode()[0])
     ```

    **Interpolation**
   - Useful for time-series data:
     ```python
     df['NumericColumn'] = df['NumericColumn'].interpolate(method='linear')
     ```

    **Forward and Backward Fill**
   - Use previous or next values:
     ```python
     # Forward fill
     df['Column'] = df['Column'].fillna(method='ffill')

     # Backward fill
     df['Column'] = df['Column'].fillna(method='bfill')
     ```

---

### **Advanced Techniques**
**K-Nearest Neighbors (KNN) Imputation**
   - Estimates missing values based on similar rows.
   ```python
   from sklearn.impute import KNNImputer

   imputer = KNNImputer(n_neighbors=5)
   df[['NumericColumn1', 'NumericColumn2']] = imputer.fit_transform(df[['NumericColumn1', 'NumericColumn2']])
   ```

**Multiple Imputation**
   - Generates multiple datasets with different imputations to reflect uncertainty.
   - Libraries like `fancyimpute` or `IterativeImputer` from `sklearn` can be used.

   ```python
   from sklearn.experimental import enable_iterative_imputer
   from sklearn.impute import IterativeImputer

   imputer = IterativeImputer()
   df[['NumericColumn']] = imputer.fit_transform(df[['NumericColumn']])
   ```

**Using Machine Learning Models**
   - Train a model to predict missing values.
   ```python
   from sklearn.ensemble import RandomForestRegressor

   # Identify rows with and without missing values
   train_data = df[df['NumericColumn'].notnull()]
   missing_data = df[df['NumericColumn'].isnull()]

   # Train a model
   model = RandomForestRegressor()
   model.fit(train_data.drop(columns=['NumericColumn']), train_data['NumericColumn'])

   # Predict missing values
   df.loc[df['NumericColumn'].isnull(), 'NumericColumn'] = model.predict(missing_data.drop(columns=['NumericColumn']))
   ```

---

### **Step 5: Visualization of Filled Values**
Compare distributions before and after imputation:
```python
sns.histplot(df['NumericColumn'], kde=True, label='After Imputation', color='blue')
sns.histplot(original_df['NumericColumn'], kde=True, label='Before Imputation', color='red')
plt.legend()
plt.show()
```

### **Best Practices for Handling Missing Values**
1. **Understand the Nature of Missingness**
   - Is it Missing Completely at Random (MCAR), Missing at Random (MAR), or Not Missing at Random (NMAR)?
   
2. **Domain Knowledge**
   - Use domain knowledge to determine the most appropriate imputation strategy.

3. **Evaluate Imputation Impact**
   - Compare results of imputed data with original data to ensure no bias is introduced.

4. **Document Your Choices**
   - Clearly note the reasons for choosing specific methods, especially in collaborative projects.

---



### **Step 5: Handling Duplicates**
```python
# Check for duplicates
print(f"Number of duplicate rows: {df.duplicated().sum()}")

# Remove duplicates
df = df.drop_duplicates()
```



### **Identify Duplicates with Custom Conditions**
Instead of dropping all duplicates, you can identify and manage duplicates based on specific columns.

#### Identify Duplicates
```python
# Find duplicates based on specific columns
duplicates = df[df.duplicated(subset=['Column1', 'Column2'], keep=False)]
print(duplicates)
```

#### Drop Duplicates
```python
# Drop duplicates based on specific columns
df_unique = df.drop_duplicates(subset=['Column1', 'Column2'], keep='first')
```

---

### **Flagging Duplicates Instead of Removing**
Add a flag to indicate which rows are duplicates.
```python
df['is_duplicate'] = df.duplicated()
```

---

### **Aggregate Duplicates**
Instead of dropping duplicates, aggregate their values.
```python
# Aggregate numerical values for duplicates
df_aggregated = df.groupby(['Column1', 'Column2'], as_index=False).sum()
```

---

### **Resolve Duplicates by Priority**
If duplicates exist, resolve them by prioritizing certain criteria.
```python
# Keep duplicates with the highest value in 'Score' column
df_resolved = df.sort_values('Score', ascending=False).drop_duplicates(subset=['Column1'], keep='first')
```

---

### **Merge Duplicate Rows**
Combine information from duplicate rows instead of removing them outright.

#### Example: Concatenate String Data
```python
# Merge duplicate rows by concatenating values in other columns
df_merged = df.groupby(['Column1'], as_index=False).agg({'Column2': ' '.join, 'NumericColumn': 'mean'})
```

---

### **Filter Duplicates with Conditional Logic**
You can retain or remove duplicates based on specific conditions.

#### Example: Keep Rows Based on Date
```python
# Keep the most recent duplicate based on a 'Date' column
df_sorted = df.sort_values('Date', ascending=False)
df_filtered = df_sorted.drop_duplicates(subset=['Column1'], keep='first')
```

---

### **Advanced Duplicate Detection**
Use similarity metrics to detect near-duplicates (e.g., typos in text data).

#### Fuzzy Matching for Text
```python
from fuzzywuzzy import fuzz
from fuzzywuzzy import process

# Find similar entries
duplicates = [fuzz.ratio(x, y) for x, y in zip(df['Column1'], df['Column1'].shift()) if fuzz.ratio(x, y) > 90]
```

#### Example: Dedupe Library
The `dedupe` library can help find fuzzy duplicates.
```bash
pip install dedupe
```
```python
import dedupe

# Prepare data for deduplication
data = df.to_dict(orient='records')

# Define deduplication fields
fields = [{'field': 'Column1', 'type': 'String'}, {'field': 'Column2', 'type': 'String'}]

# Configure deduper
deduper = dedupe.Dedupe(fields)
deduper.sample(data, 15000)

# Perform deduplication
dedupe_results = deduper.match(data, threshold=0.5)
```

---

### **Visualize Duplicate Patterns**
Visualizing duplicates can help identify patterns.
```python
import seaborn as sns

# Count duplicates for each value in a column
duplicate_counts = df['Column1'].value_counts()

# Visualize duplicate counts
sns.barplot(x=duplicate_counts.index, y=duplicate_counts.values)
plt.xticks(rotation=90)
plt.show()
```

---

### **Export Duplicates for Further Review**
Save duplicate rows to a separate file for manual inspection.
```python
duplicates = df[df.duplicated(keep=False)]
duplicates.to_csv('duplicates.csv', index=False)
```

---

### **Combine Dropping and Retaining Duplicates**
Keep one set of duplicates in the dataset while exporting the others.
```python
# Retain unique rows in the dataset
df_cleaned = df.drop_duplicates()

# Export duplicate rows for review
df_duplicates = df[~df.index.isin(df_cleaned.index)]
df_duplicates.to_csv('duplicates_to_review.csv', index=False)
```

---




### **Step 6: Encoding Categorical Variables**
```python
# One-hot encoding for 'Embarked'
df = pd.get_dummies(df, columns=['Embarked'], drop_first=True)

# Map 'Sex' column to numeric
df['Sex'] = df['Sex'].map({'male': 0, 'female': 1})
```

### **Step 7: Feature Scaling**
```python
from sklearn.preprocessing import MinMaxScaler

# Scale Age and Fare columns
scaler = MinMaxScaler()
df[['Age', 'Fare']] = scaler.fit_transform(df[['Age', 'Fare']])
```

---

## **3. Exploratory Data Analysis (EDA)**

### **Step 1: Univariate Analysis**
```python
# Distribution of Age
sns.histplot(df['Age'], kde=True, bins=30)
plt.title('Age Distribution')
plt.show()

# Count plot for Survival
sns.countplot(data=df, x='Survived')
plt.title('Survival Count')
plt.show()
```

### **Step 2: Bivariate Analysis**
```python
# Survival Rate by Gender
sns.barplot(data=df, x='Sex', y='Survived')
plt.title('Survival Rate by Gender')
plt.show()

# Fare vs Age
sns.scatterplot(data=df, x='Age', y='Fare', hue='Survived')
plt.title('Fare vs Age')
plt.show()
```

### **Step 3: Correlation Analysis**
```python
# Correlation Heatmap
corr = df.corr()
sns.heatmap(corr, annot=True, cmap='coolwarm', fmt='.2f')
plt.title('Correlation Heatmap')
plt.show()
```

---

## **4. Advanced Data Cleaning**

### **Step 1: Removing Outliers**
Use the IQR method to remove outliers:
```python
# Define a function to remove outliers
def remove_outliers(df, column):
    Q1 = df[column].quantile(0.25)
    Q3 = df[column].quantile(0.75)
    IQR = Q3 - Q1
    lower_bound = Q1 - 1.5 * IQR
    upper_bound = Q3 + 1.5 * IQR
    return df[(df[column] >= lower_bound) & (df[column] <= upper_bound)]

# Remove outliers from Fare
df = remove_outliers(df, 'Fare')
```

### **Step 2: Creating New Features**
```python
# Create a new feature: FamilySize
df['FamilySize'] = df['SibSp'] + df['Parch']

# Create Age bins
df['AgeGroup'] = pd.cut(df['Age'], bins=[0, 0.2, 0.4, 0.6, 0.8, 1.0], labels=['Child', 'Teen', 'Young Adult', 'Adult', 'Senior'])
```

---

## **5. Save the Cleaned Data**
```python
df.to_csv('cleaned_titanic_data.csv', index=False)
print("Cleaned data saved!")
```

---

