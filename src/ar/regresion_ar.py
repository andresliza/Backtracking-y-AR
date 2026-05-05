import matplotlib
matplotlib.use("Agg")

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
import os

# Leer CSV
csv_path = "src/ar/resultados_ar.csv"
df = pd.read_csv(csv_path)
df.columns = [c.strip() for c in df.columns]

# Calcular variables auxiliares
# El modelo teórico es T(N, M) = c * (N^2 * M) + d
# Como M es constante (10), el modelo es T(N) = c' * N^2 + d
df["n2"] = df["N"] ** 2

# --- REGRESION: T(N) vs N^2 ---
slope, intercept, r_value, p_value, std_err = stats.linregress(df["n2"], df["Tiempo_Mediano_us"])
r2 = r_value ** 2

# Resultados por consola
print("   Regresion lineal Tiempo ~ N^2")
print(f"  Pendiente: {slope:.6f}")
print(f"  Interseccion: {intercept:.4f}")
print(f"  R2: {r2:.6f}")
print(f"  p-valor: {p_value:.4e}")

# Crear carpeta de assets si no existe (siguiendo estilo DyV)
os.makedirs("src/ar/assets", exist_ok=True)

# 1. Grafico de dispersion y ajuste
plt.figure(figsize=(10, 6))
plt.plot(df["N"], df["Tiempo_Mediano_us"], "o", label="Tiempos medidos", markersize=4)
plt.plot(df["N"], slope * df["n2"] + intercept, "-", label=r"Ajuste $\Theta(N^2)$", color="red")
plt.xlabel("N (Número de tareas)")
plt.ylabel("Tiempo (us)")
plt.title(r"Análisis de Complejidad Avance Rápido: $T(N) \sim \Theta(N^2)$")
plt.legend()
plt.grid(True, linestyle="--", alpha=0.7)
plt.savefig("src/ar/assets/regresion_ar.pdf")
plt.savefig("src/ar/assets/regresion_ar.jpg")
plt.close()

# 2. Grafico con escala logaritmica (para ver tendencia)
plt.figure(figsize=(10, 6))
plt.scatter(df["N"], df["Tiempo_Mediano_us"], label="Tiempos medidos", marker="o", s=20)
plt.plot(df["N"], slope * df["n2"] + intercept, label=r"Ajuste $\Theta(N^2)$", color="red")
plt.xscale("log", base=10)
plt.yscale("log", base=10)
plt.xlabel("log(N)")
plt.ylabel("log(Tiempo)")
plt.title("Regresión en escala logarítmica")
plt.legend()
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.savefig("src/ar/assets/regresion_ar_log.pdf")
plt.savefig("src/ar/assets/regresion_ar_log.jpg")
plt.close()

print("\nGráficas guardadas en src/ar/assets/")
