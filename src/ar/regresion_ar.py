import matplotlib
matplotlib.use("Agg")

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy import stats
import os

# Crear carpeta de assets si no existe
os.makedirs("assets", exist_ok=True)

# Cargar datos
csv_path = "resultados_ar.csv"
df = pd.read_csv(csv_path) if os.path.exists(csv_path) else None

# --- ANALISIS GREEDY (Theta(n^2)) ---
if df is not None:
    df.columns = [c.strip() for c in df.columns]
    # El modelo teórico es T(N, M) = c * (N^2 * M) + d
    # Con M constante, T(N) ~ Theta(N^2)
    df["n_pow"] = df["N"] ** 2
    slope, intercept, r_value, p_value, std_err = stats.linregress(df["n_pow"], df["Tiempo_Mediano_us"])
    
    print(f"\n--- Análisis: Avance Rápido (Greedy) ---")
    print(f"  Modelo: O(n^2)")
    print(f"  R2: {r_value**2:.6f}")

    # Gráfica Lineal
    plt.figure()
    plt.plot(df["N"], df["Tiempo_Mediano_us"], "o", label="Tiempos medidos")
    plt.plot(df["N"], slope * df["n_pow"] + intercept, label=r"Ajuste $\Theta(n^2)$")
    plt.xlabel("n (Tareas)")
    plt.ylabel("Tiempo (us)")
    plt.title(r"Análisis AR: $T(n) \sim \Theta(n^2)$")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_ar_lineal.jpg")
    plt.close()

    # Gráfica Logarítmica (eje x log base 2)
    plt.figure()
    plt.plot(df["N"], df["Tiempo_Mediano_us"], "o", label="Tiempos medidos")
    plt.plot(df["N"], slope * df["n_pow"] + intercept, label=r"Ajuste $\Theta(n^2)$")
    plt.xscale("log", base=2)
    plt.xlabel("n (Tareas)")
    plt.ylabel("Tiempo (us)")
    plt.title(r"Análisis AR: $T(n) \sim \Theta(n^2)$ (Escala Log)")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_ar_log.jpg")
    plt.close()

    print("\nGráficas generadas con éxito en la carpeta assets/")
else:
    print(f"Error: No se encontró el archivo {csv_path}")
