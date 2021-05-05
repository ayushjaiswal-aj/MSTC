#define SUCCESS 1
#define FAILURE 0

static int (*g_pfn)(int);
static int result;

int register_callback(int(*pfn)(int)){
	g_pfn = pfn;
	return (SUCCESS);
}

void trigger_event(int n){
	result = g_pfn(n);
}

int get_result(void){
	return (result);
}
