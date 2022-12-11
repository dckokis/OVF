import numpy as np

from scipy.linalg import solve_banded


class Solver:
    def __init__(self, x0, x1, space_steps, dt):
        """
        :param x0: Beginning of space interval
        :param x1: End of space interval
        :param space_steps: Amount of space steps
        :param dt: Difference between time steps
        """
        self.dx = (x1 - x0) / (space_steps + 1)
        self.dt = dt
        self.num = space_steps
        self.xs = np.linspace(x0, x1, space_steps + 2)

        k_a = np.array([- self.dt / (2 * self.dx ** 2) for _ in self.xs[1:-1]])
        k_b = np.array([1 + self.dt / self.dx ** 2 for _ in self.xs[1:-1]])
        k_c = k_a

        cc = np.concatenate([[0], [0], k_a])
        bb = np.concatenate([[1], k_b, [1]])
        aa = np.concatenate([k_c, [0], [0]])

        self.matrix = np.row_stack([cc, bb, aa])

    def do_step(self, U):
        """
        Performs a step of Crank-Nicholson scheme
        """
        assert len(U) == self.num + 2
        k_d = np.array([self.dt / (2 * self.dx ** 2) for _ in self.xs[1:-1]])
        RightHandPArt = np.concatenate([
            [0],
            U[1:-1] + k_d * (U[:-2] - 2 * U[1:-1] + U[2:]),
            [0]
        ])
        # https://en.wikipedia.org/wiki/Band_matrix => band matrix with k1, k2 = (1,1) is a tridiagonal matrix
        return solve_banded((1, 1), self.matrix, RightHandPArt)
