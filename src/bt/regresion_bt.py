import matplotlib
matplotlib.use("Agg")

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
import os

# Leer CSV
csv_path = "src/bt/resultados.csv"
df = pd.read_csv(csv_path)
df.columns = [c.strip() for c in df.columns]

# Modelo simplificado: T(n) = c * n^4 + d
# Justificación: Aunque el peor caso es exponencial, las podas reducen 
# el comportamiento a un polinomio de grado bajo para m pequeño.
df_const = df[df["N"] >= 10].copy()
df_const["n4"] = df_const["N"] ** 4

# --- REGRESION: T(N) vs N^4 ---
slope, intercept, r_value, p_value, std_err = stats.linregress(df_const["n4"], df_const["Tiempo_Mediano_us"])
r2 = r_value ** 2

# Resultados por consola
print("   Regresion lineal Tiempo ~ N^4")
print(f"  Pendiente: {slope:.12f}")
print(f"  Interseccion: {intercept:.4f}")
print(f"  R2: {r2:.6f}")

# Crear carpeta de assets si no existe
os.makedirs("src/bt/assets", exist_ok=True)

# 1. Grafico de dispersion y ajuste
plt.figure(figsize=(10, 6))
plt.plot(df_const["N"], df_const["Tiempo_Mediano_us"], "o", label="Tiempos medidos", markersize=4)
plt.plot(df_const["N"], slope * df_const["n4"] + intercept, "-", label=r"Ajuste $\Theta(n^4)$", color="red")
plt.xlabel("N (Tamaño de población)")
plt.ylabel("Tiempo (us)")
plt.title(r"Análisis de Complejidad Backtracking: $T(n) \sim \Theta(n^4)$")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.7)
plt.savefig("src/bt/assets/regresion_bt.jpg")
plt.close()

# 2. Grafico con escala logaritmica
plt.figure(figsize=(10, 6))
plt.scatter(df_const["N"], df_const["Tiempo_Mediano_us"], label="Tiempos medidos", marker="o", s=20)
plt.plot(df_const["N"], slope * df_const["n4"] + intercept, label=r"Ajuste $\Theta(n^4)$", color="red")
plt.xscale("log", base=10)
plt.yscale("log", base=10)
plt.xlabel("log(N)")
plt.ylabel("log(Tiempo)")
plt.title("Regresión BT en escala logarítmica")
plt.legend()
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.savefig("src/bt/assets/regresion_bt_log.jpg")
plt.close()

print("\nGráficas guardadas en src/bt/assets/")
