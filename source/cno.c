#include "cno.h"


#include "cno_build_info.h"
#include "cno_environment.h"

cno_u8_type CNO_Init(){
	return (CNO_Build_Info_Init() && CNO_Environment_Init());
}
