//dreampuff_statistic.h

#ifndef DREAMPUFF_STATISTIC_H
#define DREAMPUFF_STATISTIC_H

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

#include "cno_build.h"

typedef struct DreamPuff_Statisticno_s{
	cno_utf8_type name;
	cno_utf8_type description;
	cno_u32_type value;
	cno_u32_type max;
} DreamPuff_Statisticno_t;

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //DREAMPUFF_STATISTIC_H
