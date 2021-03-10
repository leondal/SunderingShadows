#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_plea(string str) {
  if(!avatarp(TP)) return 0;
// Need random emotes...
// Crystal? Styx? :)

  CHAT_D->force_chat(TP,"petition","%^BOLD%^{plea}%^RESET%^ "+str,0);
  return 1;
}
