#ifndef program_options_h
#define program_options_h

class program_options {
public:
    program_options(int ac, char** av);
private:
    auto process_options(int ac, char** av) -> void;
};

#endif // program_options_h
