import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = pd.read_csv("/home/piri/kuBig2025/orange3/data/basket_analysis.csv")
corr = data.corr()
print(corr)

sns.heatmap(corr, annot=True, cmap="coolwarm", vmin=-1, vmax=1)
plt.show()