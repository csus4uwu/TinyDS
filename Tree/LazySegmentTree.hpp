// jiangly yyds
#ifndef LazySegmentTree_H
#define LazySegmentTree_H 1

#include <cstddef> // size_t
#include <vector>  // std::vector

template <class Info, class Tag>
struct LazySegmentTree {
    LazySegmentTree() : n(0) {}
    LazySegmentTree(size_t n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template <class T>
    LazySegmentTree(std::vector<T> const &init_) {
        init(init_);
    }

    void init(size_t n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    void modify(size_t p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(size_t l, size_t r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(size_t l, size_t r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }

    template <class F>
    size_t findFirst(size_t l, size_t r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template <class F>
    size_t findLast(size_t l, size_t r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }

private:
    size_t n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    template <class T>
    void init(std::vector<T> const &init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(size_t, size_t, size_t)> build = [&](size_t p, size_t l, size_t r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            size_t m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(size_t p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(size_t p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(size_t p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(size_t p, size_t l, size_t r, size_t x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        size_t m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    Info rangeQuery(size_t p, size_t l, size_t r, size_t x, size_t y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        size_t m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    void rangeApply(size_t p, size_t l, size_t r, size_t x, size_t y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        size_t m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    template <class F>
    size_t findFirst(size_t p, size_t l, size_t r, size_t x, size_t y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        size_t m = (l + r) / 2;
        push(p);
        size_t res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template <class F>
    size_t findLast(size_t p, size_t l, size_t r, size_t x, size_t y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        size_t m = (l + r) / 2;
        push(p);
        size_t res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
};

#endif