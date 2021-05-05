#define SUCCESS 1
#define FAILURE 0

static void* (*g_pfn) (void*);
static void* result;

int register_callback(void* (*pfn)(void*)){
	g_pfn = pfn;
	return SUCCESS;
}

void trigger_event(void* data){
	result = g_pfn(data);
}

void* get_result(void){
	return result;
}
