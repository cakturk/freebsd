// Copyright 2014 The Kyua Authors.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/// \file engine/plain.hpp
/// Execution engine for test programs that implement the plain interface.

#if !defined(ENGINE_PLAIN_HPP)
#define ENGINE_PLAIN_HPP

#include "engine/scheduler.hpp"

namespace engine {


/// Implementation of the scheduler interface for plain test programs.
class plain_interface : public engine::scheduler::interface {
public:
    void exec_list(const model::test_program&,
                   const utils::config::properties_map&) const UTILS_NORETURN;

    model::test_cases_map parse_list(
        const utils::optional< utils::process::status >&,
        const utils::fs::path&,
        const utils::fs::path&) const;

    void exec_test(const model::test_program&, const std::string&,
                   const utils::config::properties_map&,
                   const utils::fs::path&) const
        UTILS_NORETURN;

    model::test_result compute_result(
        const utils::optional< utils::process::status >&,
        const utils::fs::path&,
        const utils::fs::path&,
        const utils::fs::path&) const;
};


}  // namespace engine


#endif  // !defined(ENGINE_PLAIN_HPP)
