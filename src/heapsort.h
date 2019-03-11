#ifndef __CHAPTER4__HEAPSORT_HEAPSORT_H__
#define __CHAPTER4__HEAPSORT_HEAPSORT_H__ (1)

namespace ch4 
{
    class heapsort
    {
        private:
            template <class T>
                struct pq_t
                {
                    std::vector<T> qs;
                    using size_type = typename std::vector<T>::size_type;
                    int n = 0;

                    void print()
                    {
                        for(auto i : qs)
                        {
                            std::cout << i << " ";
                        }
                        std::cout << std::endl;
                    }
                    void insert(T val)
                    {
                        qs.emplace_back(std::move(val));
                        heapify_up();
                    }
                    T min()
                    {
                        T f(qs.front());
                        T l(qs.back());
                        qs.pop_back();
                        qs[0] = l;
                        heapify_down();
                        return f;
                    }
                    void heapify_down()
                    {
                        heapify_down(0);
                    }
                    void heapify_down(size_type n)
                    {
                        size_type q = n;
                        size_type c = (n * 2) + 1;

                        if(c < qs.size())
                        {
                            if(qs[q] > qs[c])
                            {
                                q = c;
                            }
                            if(qs[q] > qs[c+1])
                            {
                                q = c + 1;
                            }
                        }
                        if(q != n)
                        {
                            std::swap(qs[n], qs[q]);
                            heapify_down(q);
                        }
                    }
                    void heapify_up()
                    {
                        size_type n = qs.size() - 1;
                        heapify_up(n);
                    }
                    void heapify_up(size_type n)
                    {
                        if(n > 0)
                        {
                            size_type p = (n - 1) / 2;
                            if(qs[p] > qs[n])
                            {
                                std::swap(qs[p], qs[n]);
                                heapify_up(p);
                            }
                        }
                    }
                };
        public:
            template <class C> auto sort(C&& container);

    };
    template <class C> 
        auto heapsort::sort(C&& container)
        {
            pq_t<typename std::remove_reference_t<C>::value_type> pq;
            for(auto i : container)
            {
                pq.insert(i);
            }

            for(typename std::remove_reference_t<C>::size_type i = 0; i < container.size(); i++)
            {
                container[i] = pq.min();
            }
            return container;
        }
}
#endif //! __CHAPTER4__HEAPSORT_HEAPSORT_H__ (1)

