workspace(name = "mersenne")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

lucas_version="master"
toolchain_version="bazel_0.26"

http_archive(
    name = "lucas",
    urls = [
        "https://github.com/stardog-union/lucas/archive/%s.zip" % lucas_version,
    ],
    strip_prefix = "lucas-%s" % lucas_version,
)

http_archive(
    name = "toolchain",
    urls = [
        "https://github.com/stardog-union/toolchain/archive/%s.zip" % toolchain_version,
    ],
    strip_prefix = "toolchain-%s" % toolchain_version,
    # urls = [
    #     "file:../toolchain.tgz",
    # ],
    # strip_prefix = "toolchain",
)

load("@toolchain//cpp:toolchains.bzl", "cpp_register_toolchains")
cpp_register_toolchains("@toolchain")
