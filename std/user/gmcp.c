/*
  gmcp.c
  
  User.c inherit to add GMCP functionality.
  
  -- Tlaloc -- 9.16.21
*/

void gmcp_enable()
{
    write("<GMCP negotiation enabled.>\n");
}

void gmcp(string str)
{
    write("<GMCP request received.>\n");
    write(str);
    write("\n\<GMCP request end.>\n");
}

void send_gcmp(string str)
{
    efun::send_gmcp(str);
}