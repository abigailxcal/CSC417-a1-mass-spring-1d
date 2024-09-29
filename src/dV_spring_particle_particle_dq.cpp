#include <dV_spring_particle_particle_dq.h>

// populates dV with the  first derivative of the potential eneergy with respect to the general cooordinates
// by definition, f(q) = -dV(q)
void dV_spring_particle_particle_dq(Eigen::VectorXd &dV, const Eigen::VectorXd &q, double stiffness) {
    dV.resize(1); //becomes a vector with a single element, but can still be resized
    dV = stiffness * q;
}