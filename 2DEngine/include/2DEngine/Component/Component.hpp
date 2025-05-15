#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>
#include <cstdint>

const uint32_t DEFAULT_UPDATE_ORDER = 100;

class Component {
    public :
        Component(const std::string& i_component_name,class Actor* i_owner_actor =nullptr ,uint32_t i_update_order = DEFAULT_UPDATE_ORDER);
        ~Component();
        std::string getComponentName();
        uint32_t getUpdateOrder();
        void setComponentOwner(class Actor* i_owner_actor);
        class Actor* getComponentOwner(); 
        virtual void update(float i_delta_time_s);
        virtual void onStart();
    protected:  
        class Actor* m_owner_actor = nullptr;
    private:
        std::string m_component_name;
        uint32_t m_update_order;
};
#endif //COMPONENT_HPP 