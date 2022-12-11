from matplotlib import animation
from matplotlib import pyplot as plt
import numpy as np
import matplotlib

matplotlib.use("TkAgg")


def AnimateSolution2D(xx: np.array, yy: np.array, zz: list):
    def update_plot_2D(frame):
        nonlocal plot
        plot.remove()
        plot = plot = ax.pcolormesh(xx, yy, zz[frame], cmap='magma', vmin=0, vmax=1)
        return plot,

    fig = plt.figure(figsize=(100, 100), dpi=200)
    ax = plt.axes()
    plot = ax.pcolormesh(xx, yy, zz[0])
    fig.colorbar(plot, ax=ax)
    ax.set_title('2D Heat map')
    anim = animation.FuncAnimation(fig, update_plot_2D, len(zz), interval=30)
    plt.show()


def AnimateSolution3D(xx: np.array, yy: np.array, zz: list):
    def update_plot(frame):
        nonlocal plot
        plot.remove()
        plot = ax.plot_surface(xx, yy, zz[frame], cmap='magma', vmin=0, vmax=1)
        return plot,

    fig = plt.figure(figsize=(100, 100), dpi=200)
    ax = plt.axes(projection='3d')
    ax.set_zlim(0, 1)
    plot = ax.plot_surface(xx, yy, zz[0])
    fig.colorbar(plot, ax=ax)
    ax.set_title('Heat map')
    anim = animation.FuncAnimation(fig, update_plot, len(zz), interval=30)
    plt.show()
