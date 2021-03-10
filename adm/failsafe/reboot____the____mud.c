#include <std.h>
#include <security.h>
#include <objects.h>
#include <rooms.h>
#include <daemons.h>


void create()
{
    seteuid(UID_SHUTDOWN);
    call_other(SHUT_D, "startShutdown",4,1);
}