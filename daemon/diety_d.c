//ACIVELY USED - By temple/church
//Seems like this could be absorbed into something else

#include <std.h>
#include <dieties.h>


int allowed_follow(string name, string divinity) {
  name = lower_case(name);
  divinity = lower_case(divinity);
  if ((int)"/daemon/save_d"->is_member(divinity+"_displeased",name) == -1) {
  return 1;
  }  else {
  return 0;
  }

}
