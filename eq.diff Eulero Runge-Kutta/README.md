For run this program must need to have install ROOT-CERN for doing the plots.

Implementation of a code for the numerical solution of a differential equation describing the motion of a harmonic oscillator using Euler's method and than Runge Kutta 4-th order. 

We next graphed the trend of the position as a function of time as the integration step varies and compared it to the exact solution.

We define an abstract class VectorFunctionBase with a single Eval method, purely virtual, that given a vector and a double, representing time, returns the value of the first derivative at the point and time considered.

From this abstract class, we derive a concrete class that describes the mode laws of a harmonic oscillator, allowing to define its frequency.

Let's define an abstract class EquationDifferentialBase which has only one method Step, purely virtual, which given the time t, a vector x, the integration step h and a pointer to a FunctionBaseVector, returns an estimate of the value of the position x at time t+h. 

From this abstract class, we derive a concrete class that implements Euler's method. 

Let us consider Newton's second law of dimanics

a=d2x/dt2 = F/m

which is a second-order differential equation that can be reduced to a first-order differential equation by introducing the variable velocity

dx/dt = v
dv/dt = F/m

Euler's method is to calculate the state of the solution at time t+h given that at a time t by the expressions:

x(t+h) = x(t) + h*dx/dt = x(t) + h*v
v(t+h) = v(t) + h*dv/dt = v(t) + h*F/m

The Runge-Kutta method is a fourth-order method and uses the following increment determination:

k1 = dx/dt(t,x)
k2 = dx/dt(t+h/2,x+k1*h/2)
k3 = dx/dt(t+h/2,x+k2*h/2)
k4 = dx/dt(t+h,x+k3*h)
x(t+h) = x(t) + (k1+ 2*k2+2*k3 + k4)*(h/6)

