import {Link, useParams} from "react-router-dom";
import axios from "axios";
import {useEffect, useState} from "react";
import {ClockLoader} from "react-spinners";

const DetailsPage = () => {
    const {doctorId} = useParams()
    const [doctor, setDoctor] = useState()
    const [loading, setLoading] = useState(true)

    useEffect(() => {
        getDetails();
    }, []);
    const getDetails = () => {
        setLoading(true)
        axios.get(`/api/doctors/${doctorId}`)
            .then((r) => {
                setDoctor(r.data)
            })
            .catch((error) => {})
            .finally(() => {
                setLoading(false)
            })
    }

    if (loading) {
        return <div className="h-full w-full flex justify-center items-center">
            <ClockLoader color="white" />
        </div>
    }

    return (
        <>
            <Link to="/" className="border rounded-2xl p-3 absolute top-3 left-3" >Go back</Link>
            <div className="flex h-full justify-center p-10">
                <div className="w-1/2 bg-[#011a2c] bg-opacity-80 text-center py-10 px-3 rounded-2xl border-blue-400 border-3">
                    <div className="text-5xl mb-10">{doctor?.name}</div>
                    <div className="text-large mb-10">{doctor?.phone}</div>
                    <div className="text-large mb-10">{doctor?.specialization}</div>
                    <div className="text-large mb-10">{doctor?.info}</div>
                </div>
            </div>
        </>
    );
};

export default DetailsPage;