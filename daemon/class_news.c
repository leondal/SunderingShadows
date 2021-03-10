//TO loop through a class and send a message... cuz I'm too
//lazy to figure out how to use CHAT_D

#include <std.h>

void class_news(string myclass, string mess){
  "/daemon/messaging_d"->avatars_message("combat","%^BOLD%^(Imm): "+capitalize(myclass)+" News: "+mess,({ }));
}
