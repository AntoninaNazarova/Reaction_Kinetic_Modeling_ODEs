# Reaction_Kinetic_Modeling_ODEs
This repository features Python and C++ implementations for "Copper(I)-Catalyzed Formation of 5-Bismuth(III) Triazolides Derived with In Situ Cyclic Voltammetry" by Nazarova et al., as featured in Frontiers in Chemistry, Vol. 10, 2022 (DOI: 10.3389/fchem.2022.830237).


This repository features Python and C++ implementations for the mechanistic modeling of copper(I)-catalyzed reaction of the formation of 5-bismuth(III) triazolides developed for "Copper(I)-Catalyzed Formation of 5-Bismuth(III) Triazolides Derived with In Situ Cyclic Voltammetry" by Nazarova et al., as featured in Frontiers in Chemistry, Vol. 10, 2022 (DOI: 10.3389/fchem.2022.830237). The code is grounded in a mechanistic model that employs ordinary differential rate equations (ODEs) and was designed to investigate both direct and reverse rate constants, shedding light on their roles in equilibrium processes in kinetics of copper(I)-catalyzed reaction of 5-bismuth(III) triazolides formation.

  Data Files
•	Data_A_new1.dat: Contains concentrations of species participating in the electron transfer, derived from peak current in a cyclic voltammogram using the Randles-Sevcik equation (equation 6 in the referenced paper).
•	time.dat: Contains corresponding time data for the concentrations in Data_A_new1.dat.


  Computational Model
The integration of the ODEs is performed using a self-developed computer program based on the fourth-order classical Runge-Kutta method. The initial concentrations of the copper(I) catalyst, bismuth(III) acetylide, and azide are defined by the experimental setup and must be specified when using this code for different systems.


  Citation
For academic research purposes, if you utilize this code or its derivatives, please cite the following paper:
Nazarova, A. L., et al. "Copper(I)-Catalyzed Formation of 5-Bismuth(III) Triazolides Derived with In Situ Cyclic Voltammetry." Frontiers in Chemistry, vol. 10, 2022, doi: 10.3389/fchem.2022.830237.
