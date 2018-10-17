workspace(name = "mersenne")

http_archive(
    name = "lucas",
    urls = [
        "https://github.com/stardog-union/lucas/archive/master.zip",
    ],
    strip_prefix = "lucas-master",
)

http_archive(
    name = "toolchain",
    urls = [
        # The file: URL is useful for testing the build, but is not generally necessary since Bazel handles caching
        # external dependencies.
        # TODO(james): Remove this URL when the Bazel build is stable.
        # "file:///home/james/git/toolchain-master.tgz",
        "https://github.com/stardog-union/toolchain/archive/master.zip",
    ],
    strip_prefix = "toolchain-master",
)
