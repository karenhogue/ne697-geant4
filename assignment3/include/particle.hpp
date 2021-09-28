#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace mc1d {
    class Particle {
        public:
            Particle (int particle_ID);

            //getters for member attributes
            int get_particle_ID() const;
            int get_particle_location() const;
            bool get_alive() const;
            //setter to allow change to particle location and alive status
            void set_alive(bool const& alive) { m_alive = alive; return;}
            void set_particle_location(int const& particle_ID) { m_particleID = particle_ID; return;}
        
        private:
            int m_particleLocation;
            float m_particleID;
            bool m_alive;
    };
}

#endif