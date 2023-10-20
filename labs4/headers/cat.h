class Cat{
    public:
        Cat(char *name);
        void set_name(char *name);
        char* get_name();
        void print_name();
    
    private:
        char *name;
};
