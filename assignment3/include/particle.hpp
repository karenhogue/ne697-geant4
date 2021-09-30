#ifndef PARTICLE_HPP
#define PARTICLE_HPP

namespace mc1d {
    class Particle {
        public:
            Particle (int particle_ID);

            int get_particle_ID() const;
            int get_particle_location() const;
            bool get_alive() const;
            //setters to allow change to particle location and alive status
            void set_alive(bool const& alive);
            void set_particle_location(int const& particle_ID);
        
        private:
            int m_particleLocation;
            int m_particleID;
            bool m_alive;
    };
}

#endif