import numpy as np

def read_data_from_file(filename):
    try:
        return np.loadtxt(filename)
    except IOError as e:
        print(f"Error opening {filename}: {e}")
        return None

def runge_kutta(s, ds):
    a0 = 0.00535
    cat0 = 0.00058 * 2.
    h = 0.01
    sum1 = 10000.
    best_ka = best_kma = 0.0  # Best ka and kma

    for i2 in range(500, 6000):
        ka = 0.005 * i2
        for i3 in range(1, 3000):
            kma = 0.00001 * i3

            cat = cat0
            sum = 0.0
            i1 = 0
            for i in range(len(s)):
                if i1 >= len(ds):
                    break

                r7 = i * h
                r8 = (i + 1) * h
                k11 = -ka * (a0 - cat0 + cat) * cat + kma * (cat0 - cat)
                k21 = -ka * (a0 - cat0 + (cat + 0.5 * h * k11)) * (cat + 0.5 * h * k11) + kma * (cat0 - (cat + 0.5 * h * k11))
                k31 = -ka * (a0 - cat0 + (cat + 0.5 * h * k21)) * (cat + 0.5 * h * k21) + kma * (cat0 - (cat + 0.5 * h * k21))
                k41 = -ka * (a0 - cat0 + (cat + h * k31)) * (cat + h * k31) + kma * (cat0 - (cat + h * k31))

                cat += h / 6.0 * (k11 + 2.0 * k21 + 2.0 * k31 + k41)

                if ds[i1] >= r7 and ds[i1] < r8:
                    sum += np.power((1.0 - s[i1] / cat), 2.0)
                    i1 += 1

            if sum1 > np.sqrt(sum):
                sum1 = np.sqrt(sum)
                best_ka = ka
                best_kma = kma

            print(f"i2= {i2} i3= {i3} sum= {sum:.3f} sum1= {sum1:.3f} ka= {best_ka:.3f} kma= {best_kma:.3f}")

if __name__ == "__main__":
    s = read_data_from_file("data_A1_new.dat")
    ds = read_data_from_file("time.dat")

    if s is not None and ds is not None:
        runge_kutta(s, ds)
