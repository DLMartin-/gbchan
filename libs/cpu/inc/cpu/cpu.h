#ifndef CPU_INC_CPU_CPU_H_
#define CPU_INC_CPU_CPU_H_
#include <cstdint>

namespace gb {
  class cpu {
    enum struct stack_pointer : std::uint16_t {};
    enum struct program_counter : std::uint16_t {};
    enum struct opcode : std::uint8_t {};

    public:
      std::uint16_t run_cycle() noexcept;

    private:
      stack_pointer sp_ {0};
      program_counter pc_ {0};
      std::uint16_t cycles_run_ {0};
  };
}

#endif

