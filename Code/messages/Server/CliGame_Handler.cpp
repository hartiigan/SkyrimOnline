/******************************************************************/
/*          This file was generated, do not modify it !!!!        */
/******************************************************************/

#include "PacketHandler.h"
#include "CliGame_Handler.h"

extern void HandleCliGame_HelloRecv(const Messages::CliGame_HelloRecv& aMsg);
extern void HandleCliGame_ChatRecv(const Messages::CliGame_ChatRecv& aMsg);

namespace Messages
{
    void CliGame_Handler::HandleBuffer(ReadBuffer* pBuffer, uint16_t aOpcode, uint16_t aConnectionId)
    {
        switch(aOpcode)
        {
            case CliGame_Hello_Opcode:
            {
                CliGame_HelloRecv msg;
                msg.connectionId = aConnectionId;
                msg.Deserialize(pBuffer);
                HandleCliGame_HelloRecv(msg);
                break;
            }
            case CliGame_Chat_Opcode:
            {
                CliGame_ChatRecv msg;
                msg.connectionId = aConnectionId;
                msg.Deserialize(pBuffer);
                HandleCliGame_ChatRecv(msg);
                break;
            }
        }
    }
}
