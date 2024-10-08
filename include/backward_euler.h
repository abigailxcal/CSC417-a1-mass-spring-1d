#include <Eigen/Dense>

//Input:
//  q - generalized coordiantes for the mass-spring system
//  qdot - generalized velocity for the mass spring system
//  dt - the time step in seconds
//  mass - the mass
//  force(q, qdot) - a function that computes the force acting on the mass as a function. This takes q and qdot as parameters.
//  stiffness(q, qdot) - a function that computes the stiffness (negative second derivative of the potential energy). This takes q and qdot as parameters.  
//Output:
//  q - set q to the updated generalized coordinate using Backward Euler time integration
//  qdot - set qdot to the updated generalized velocity using Backward Euler time integration

template<typename FORCE, typename STIFFNESS> 
inline void backward_euler(Eigen::VectorXd &q, Eigen::VectorXd &qdot, double dt, double mass,  FORCE &force, STIFFNESS &stiffness) {
    //Eigen::VectorXd  - a vector of doubles with a dynamic size (size unknown at compile time)

    //populate K with the stiffness matrix
    Eigen::VectorXd K = stiffness(q,qdot); 

    // negate the stiffness constant 
    double k = -K(0,0); 

    Eigen::VectorXd qdot_old = qdot;
    Eigen::VectorXd  q_old = q;
    //double f = force(q_old,qdot_old); don't need force right now
    double coeff = (1 + ( dt * dt * k / mass));
    q = ( dt * qdot_old + q_old ) / coeff;
    qdot = ( qdot - ( dt * k / mass) * q_old ) / coeff;

}