from numpy.fft import fft
from pico_com import PicoCom
from matplotlib import pyplot as plt
from matplotlib import animation
from matplotlib import style
import numpy as np


Pico_HW = PicoCom()

def main():
    Pico_HW.main()

if __name__ == "__main__":
    main()