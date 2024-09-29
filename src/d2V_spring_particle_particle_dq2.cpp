#include <d2V_spring_particle_particle_dq2.h>

// populates H with the second derivative of the potential energy with respect to q
// I'm assuming H represents the Hessian Matrix of PE, which is a matrix that stores second order partial derivatives 
// By definition, the stiffness matrix K = dF(q) = d2V(q)
void d2V_spring_particle_particle_dq2(Eigen::MatrixXd &H, const Eigen::VectorXd &q, double stiffness) {
    H.resize(1,1);
    H(0, 0) = 1.0;
    // H = 1.0 * stiffness
    H *= stiffness;
    
}