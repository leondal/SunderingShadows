#include <std.h>

inherit DAEMON;

void cmd_dummy() 
{
    tell_object(TP,"%^RED%^Creating Test Dummy.%^RESET%^");
    tell_room(ETP,"%^RED%^"+TP->QCN+" snaps "+TP->QP+" fingers "
        "and a test dummy appears.%^RESET%^",TP);
    new("/realms/ares/testdummy")->move(ETP);
    return 1;
}
