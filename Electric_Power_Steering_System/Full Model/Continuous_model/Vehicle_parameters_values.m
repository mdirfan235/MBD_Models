% Vehicle parameter values for Vehicle Model V1 %

%___________________________________________________________%


% ENGINE %

Engine.maxtorque = 250; %Nm


%TRANSMISSION%

Transmission.gearratio = 4; 
Transmission.gearefficiency = 0.95; %percentage

%FINAL DRIVE%

Finaldrive.gearratio = 3.8;



%VEHICLE%

Vehicle.wheel_radius = 0.30; %m

Vehicle.MaxBrakeForce_N = 8000; %N

Vehicle.mass_kg = 1500 %kg

Vehicle.Crr= 0.015; %no unit

Vehicle.g=9.8; %m/s2

Vehicle.rho = 1.225; 

Vehicle. Area = 2.2; %m2

Vehicle.dragcoeff = 0.30 ;

Vehicle.wheelbase = 0.3; %m

Vehicle.steering_rack_gear_ratio = 16; 

Vehicle.speedvalues = [0 10 20 30 40 50 60 70 80 90 100 110 120 130 140 150 160 170 180]; %kph

Vehicle.torquegains = [1.00 0.98 0.95 0.90 0.82 0.74 0.66 0.58 0.50 0.44 0.38 0.34 0.30 0.27 0.24 0.22 0.20 0.18 0.16]; %no unit

MinCruiseSpd = 20; % kmph
