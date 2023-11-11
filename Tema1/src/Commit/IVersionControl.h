namespace MyGit {
    class IVersionControlObject {
    public:
        virtual ~IVersionControlObject() = default;
        virtual int getId() const = 0;
        virtual char* getMessage() const = 0;
        virtual void display() const = 0; 
    };
}
