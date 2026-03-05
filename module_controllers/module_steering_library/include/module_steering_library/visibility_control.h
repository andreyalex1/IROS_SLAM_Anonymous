// Copyright (c) 2023, Stogl Robotics Consulting UG (haftungsbeschränkt)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef System_STEERING_LIBRARY__VISIBILITY_CONTROL_H_
#define System_STEERING_LIBRARY__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define System_STEERING__VISIBILITY_EXPORT __attribute__((dllexport))
#define System_STEERING__VISIBILITY_IMPORT __attribute__((dllimport))
#else
#define System_STEERING__VISIBILITY_EXPORT __declspec(dllexport)
#define System_STEERING__VISIBILITY_IMPORT __declspec(dllimport)
#endif
#ifdef System_STEERING__VISIBILITY_BUILDING_DLL
#define System_STEERING__VISIBILITY_PUBLIC System_STEERING__VISIBILITY_EXPORT
#else
#define System_STEERING__VISIBILITY_PUBLIC System_STEERING__VISIBILITY_IMPORT
#endif
#define System_STEERING__VISIBILITY_PUBLIC_TYPE System_STEERING__VISIBILITY_PUBLIC
#define System_STEERING__VISIBILITY_LOCAL
#else
#define System_STEERING__VISIBILITY_EXPORT __attribute__((visibility("default")))
#define System_STEERING__VISIBILITY_IMPORT
#if __GNUC__ >= 4
#define System_STEERING__VISIBILITY_PUBLIC __attribute__((visibility("default")))
#define System_STEERING__VISIBILITY_PROTECTED __attribute__((visibility("protected")))
#define System_STEERING__VISIBILITY_LOCAL __attribute__((visibility("hidden")))
#else
#define System_STEERING__VISIBILITY_PUBLIC
#define System_STEERING__VISIBILITY_LOCAL
#endif
#define System_STEERING__VISIBILITY_PUBLIC_TYPE
#endif

#endif  // System_STEERING_LIBRARY__VISIBILITY_CONTROL_H_
