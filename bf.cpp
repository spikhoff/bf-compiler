#include <iostream>
#include <vector>

class BrainfuckInterpreter {
private:
    std::vector<char> tape;
    int pointer;

public:
    BrainfuckInterpreter() : tape(30000, 0), pointer(0) {}

    void interpret(const std::string& code) {
        int loop_count = 0;
        for (size_t i = 0; i < code.size(); ++i) {
            char instruction = code[i];
            switch (instruction) {
                case '>':
                    ++pointer;
                    break;
                case '<':
                    --pointer;
                    break;
                case '+':
                    ++tape[pointer];
                    break;
                case '-':
                    --tape[pointer];
                    break;
                case '.':
                    std::cout << tape[pointer];
                    break;
                case ',':
                    std::cin >> tape[pointer];
                    break;
                case '[':
                    if (tape[pointer] == 0) {
                        loop_count = 1;
                        while (loop_count != 0) {
                            ++i;
                            if (code[i] == '[')
                                ++loop_count;
                            else if (code[i] == ']')
                                --loop_count;
                        }
                    }
                    break;
                case ']':
                    if (tape[pointer] != 0) {
                        loop_count = 1;
                        while (loop_count != 0) {
                            --i;
                            if (code[i] == ']')
                                ++loop_count;
                            else if (code[i] == '[')
                                --loop_count;
                        }
                    }
                    break;
                default:
                    // Ignore other characters
                    break;
            }
        }
    }
};

int main() {
    std::string code = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>.<+++++++.";
    BrainfuckInterpreter interpreter;
    interpreter.interpret(code);
    return 0;
}
