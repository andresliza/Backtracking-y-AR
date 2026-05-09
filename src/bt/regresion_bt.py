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
df_peor = pd.read_csv("resultados_peor.csv") if os.path.exists("resultados_peor.csv") else None
df_mejor = pd.read_csv("resultados_mejor.csv") if os.path.exists("resultados_mejor.csv") else None

# --- ANALISIS PEOR CASO (Theta(n^5)) ---
if df_peor is not None:
    df_peor["n_pow"] = df_peor["N"] ** 5
    slope, intercept, r_value, _, _ = stats.linregress(df_peor["n_pow"], df_peor["Tiempo_Mediano_us"])
    
    print(f"\n--- Análisis: Peor Caso ---")
    print(f"  Modelo: Theta(n^5)")
    print(f"  R2: {r_value**2:.6f}")

    # Gráfica Lineal
    plt.figure()
    plt.plot(df_peor["N"], df_peor["Tiempo_Mediano_us"], "o", label="PeorCaso")
    plt.plot(df_peor["N"], slope * df_peor["n_pow"] + intercept, label=r"Ajuste $\Theta(n^5)$")
    plt.xlabel("n")
    plt.ylabel("Tiempo (us)")
    plt.title(r"Peor caso $\sim \Theta(n^5)$")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_bt_peor_lineal.jpg")
    plt.close()

    # Gráfica Logarítmica (eje x log base 2)
    plt.figure()
    plt.plot(df_peor["N"], df_peor["Tiempo_Mediano_us"], "o", label="PeorCaso")
    plt.plot(df_peor["N"], slope * df_peor["n_pow"] + intercept, label=r"Ajuste $\Theta(n^5)$")
    plt.xscale("log", base=2)
    plt.xlabel("n")
    plt.ylabel("Tiempo (us)")
    plt.title(r"Peor caso $\sim \Theta(n^5)$ (Escala Log)")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_bt_peor_log.jpg")
    plt.close()

# --- ANALISIS MEJOR CASO (Theta(n^2)) ---
if df_mejor is not None:
    df_mejor["n_pow"] = df_mejor["N"] ** 2
    slope, intercept, r_value, _, _ = stats.linregress(df_mejor["n_pow"], df_mejor["Tiempo_Mediano_us"])
    
    print(f"\n--- Análisis: Mejor Caso ---")
    print(f"  Modelo: Theta(n^2)")
    print(f"  R2: {r_value**2:.6f}")

    # Gráfica Lineal
    plt.figure()
    plt.plot(df_mejor["N"], df_mejor["Tiempo_Mediano_us"], "o", label="MejorCaso")
    plt.plot(df_mejor["N"], slope * df_mejor["n_pow"] + intercept, label=r"Ajuste $\Theta(n^2)$")
    plt.xlabel("n")
    plt.ylabel("Tiempo (us)")
    plt.title(r"Mejor caso $\sim \Theta(n^2)$")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_bt_mejor_lineal.jpg")
    plt.close()

    # Gráfica Logarítmica (eje x log base 2)
    plt.figure()
    plt.plot(df_mejor["N"], df_mejor["Tiempo_Mediano_us"], "o", label="MejorCaso")
    plt.plot(df_mejor["N"], slope * df_mejor["n_pow"] + intercept, label=r"Ajuste $\Theta(n^2)$")
    plt.xscale("log", base=2)
    plt.xlabel("n")
    plt.ylabel("Tiempo (us)")
    plt.title(r"Mejor caso $\sim \Theta(n^2)$ (Escala Log)")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_bt_mejor_log.jpg")
    plt.close()

# --- COMPARATIVA ---
if df_peor is not None and df_mejor is not None:
    plt.figure()
    plt.scatter(df_mejor["N"], df_mejor["Tiempo_Mediano_us"], label="MejorCaso", marker="o")
    plt.scatter(df_peor["N"], df_peor["Tiempo_Mediano_us"], label="PeorCaso", marker="x")
    plt.xlabel("n")
    plt.ylabel("Tiempo (us)")
    plt.title("Mejor y Peor Caso")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_bt_comparativa.jpg")
    plt.close()

    # Comparativa Log
    plt.figure()
    plt.scatter(df_mejor["N"], df_mejor["Tiempo_Mediano_us"], label="MejorCaso", marker="o")
    plt.scatter(df_peor["N"], df_peor["Tiempo_Mediano_us"], label="PeorCaso", marker="x")
    plt.xscale("log", base=2)
    plt.xlabel("n")
    plt.ylabel("Tiempo (us)")
    plt.title("Mejor y Peor Caso (Escala Log)")
    plt.legend()
    plt.grid(True)
    plt.savefig("assets/regresion_bt_comparativa_log.jpg")
    plt.close()

print("\nGráficas generadas con éxito en la carpeta assets/")
