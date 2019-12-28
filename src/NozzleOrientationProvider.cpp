#include "NozzleOrientationProvider.hpp"

NozzleOrientationProvider::NozzleOrientationProvider()
{

}

AttitudeMsg NozzleOrientationProvider::getAttitude()
{
    return m_att;
}

HeadingMsg NozzleOrientationProvider::getHeading()
{
    return m_heading;
}

Vector3D<float> NozzleOrientationProvider::getBodyRate()
{
    return m_rate;
}

void NozzleOrientationProvider::receive_msg_data(DataMessage* t_msg)
{
    if(t_msg->getType() == msg_type::NOZZLEMSG)
    {
        NozzleOrientationMsg* t_nozzle_msg = (NozzleOrientationMsg*) t_msg;
        m_att.pitch = t_nozzle_msg->pitch;
        m_heading.yaw = t_nozzle_msg->yaw;
        //Logger::getAssignedLogger()->log("pitch: %f", m_att.pitch, LoggerLevel::Info);
        //Logger::getAssignedLogger()->log("yaw: %f", m_heading.yaw, LoggerLevel::Info);
    }
    else if(t_msg->getType() == msg_type::THREEAXISSENSORMSG)
    {
        ThreeAxisSensorMsg* t_rate_msg = (ThreeAxisSensorMsg*) t_msg;
        m_rate.x = t_rate_msg->data.x;
        m_rate.y = t_rate_msg->data.y;
        m_rate.z = t_rate_msg->data.z;
        // Logger::getAssignedLogger()->log("x: %f", m_rate.x, LoggerLevel::Info);
        // Logger::getAssignedLogger()->log("y: %f", m_rate.y, LoggerLevel::Info);
        // Logger::getAssignedLogger()->log("z: %f", m_rate.z, LoggerLevel::Info);
    }
}