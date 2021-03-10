#include <std.h>

string *buffer;

void force_me(string cmd)
{
    command(cmd);
}

void receive_message(string msg_class, string msg)
{
    buffer += ({msg});
}

void clear_buffer()
{
    buffer = ({});
}

string *query_buffer()
{
    return buffer;
}

void remove()
{
    destruct(TO);
}
