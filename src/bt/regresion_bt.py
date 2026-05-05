import matplotlib
matplotlib.use("Agg")

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
from scipy.special import comb
import os

# Leer CSV
csv_path = "src/bt/resultados.csv"
df = pd.read_csv(csv_path)
df.columns = [c.strip() for c in df.columns]

# El modelo teórico estimado es T(n, m) = c * n * comb(n, m) + d
# Como M se estabiliza en 5 para n >= 10, usamos comb(n, 5) * n
# Filtramos n >= 10 para tener M constante
df_const = df[df["N"] >= 10].copy()
df_const["n_comb_nm"] = df_const["N"] * comb(df_const["N"], 5)

# --- REGRESION: T(N) vs N * comb(N, 5) ---
slope, intercept, r_value, p_value, std_err = stats.linregress(df_const["n_comb_nm"], df_const["Tiempo_Mediano_us"])
r2 = r_value ** 2

# Resultados por consola
print("   Regresion lineal Tiempo ~ N * comb(N, 5)")
print(f"  Pendiente: {slope:.12f}")
print(f"  Interseccion: {intercept:.4f}")
print(f"  R2: {r2:.6f}")
print(f"  p-valor: {p_value:.4e}")

# Crear carpeta de assets si no existe
os.makedirs("src/bt/assets", exist_ok=True)

# 1. Grafico de dispersion y ajuste
plt.figure(figsize=(10, 6))
plt.plot(df_const["N"], df_const["Tiempo_Mediano_us"], "o", label="Tiempos medidos", markersize=4)
plt.plot(df_const["N"], slope * df_const["n_comb_nm"] + intercept, "-", label=r"Ajuste $\Theta(n \cdot \binom{n}{5})$", color="red")
plt.xlabel("N (Tamaño de población)")
plt.ylabel("Tiempo (us)")
plt.title(r"Análisis de Complejidad Backtracking: $T(n) \sim \Theta(n \cdot \binom{n}{5})$")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.7)
plt.savefig("src/bt/assets/regresion_bt.jpg")
plt.close()

# 2. Grafico con escala logaritmica
plt.figure(figsize=(10, 6))
plt.scatter(df_const["N"], df_const["Tiempo_Mediano_us"], label="Tiempos medidos", marker="o", s=20)
plt.plot(df_const["N"], slope * df_const["n_comb_nm"] + intercept, label=r"Ajuste $\Theta(n \cdot \binom{n}{5})$", color="red")
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
