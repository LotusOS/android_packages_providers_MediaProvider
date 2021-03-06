/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "FuseDaemon"

#include "android-base/logging.h"
#include "jni.h"

namespace mediaprovider {
int register_android_providers_media_FuseDaemon(JavaVM* vm, JNIEnv* env);
}

extern "C" jint JNI_OnLoad(JavaVM* vm, void* /* reserved */) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        LOG(ERROR) << "ERROR: GetEnv failed";
        return JNI_ERR;
    }

    mediaprovider::register_android_providers_media_FuseDaemon(vm, env);

    return JNI_VERSION_1_6;
}
